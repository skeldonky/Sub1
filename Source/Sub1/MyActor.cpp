// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	//
	UE_LOG(LogTemp, Warning, TEXT("start"));

	start.Set(0.0f, 0.0f);  // 시작 좌표 X와 Y를 0으로 설정
	totDist = 0;			// 총 이동거리를 0으로 설정

	// 확인용 로그 출력
	UE_LOG(LogTemp, Warning, TEXT("Start Position: X = %f, Y = %f"), start.X, start.Y);

	//이동
	move();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//거리구하기
float AMyActor::distance(FVector2D first, FVector2D second)
{
	//거리구하기
	double deltaX = second.X - first.X;
	double deltaY = second.Y - first.Y;

	//결과값
	float result = sqrt(deltaX * deltaX + deltaY * deltaY);

	return result;
}

//move 호출시 이동
void AMyActor::move()
{
	//이벤트 카운팅용;
	int cntEvent = 0;

	//10번이동이니 10번 반복
	for (int i = 0; i < 10; i++)
	{
		//X, Y 이동거리 0~1
		int32 XmovNum = 0;
		int32 YmovNum = 0;

		//이동거리 0 서있는거 방지
		while (true)
		{
			//X, Y 이동거리 0~1
			XmovNum = step();
			YmovNum = step();

			//둘 다 0이면 다시 실행 하나라도 1이면 나가기
			if (!(XmovNum == 0 && YmovNum == 0))
			{
				break;
			}
		}

		//이동 좌표 확인용
		FVector2D beforeMov = start;	// 움직이기 전 좌표값
		FVector2D afterMov;				// 움직인 후 좌표값

		start.X = start.X + XmovNum;
		start.Y = start.Y + YmovNum;

		afterMov = start;

		//거리 구하기
		float dist = distance(beforeMov, afterMov);

		//총 이동거리 저장
		totDist += dist;

		//이동 좌표 로그 출력
		UE_LOG(LogTemp, Warning, TEXT("Move Position: X = %f, Y = %f"), start.X, start.Y);
		//이동 거리 로그 출력
		UE_LOG(LogTemp, Warning, TEXT("Move Distance: %f"), dist);

		const int32 minNum = 0;
		const int32 maxNum = 1;
		int32 randNum = FMath::RandRange(minNum, maxNum);

		//랜덤 이벤트 0 or 1 50%
		if (randNum == 0)
		{
			cntEvent++;
			int32 randEvenNum = createEvent();
			UE_LOG(LogTemp, Warning, TEXT("Random Event Message Number : %d"), randEvenNum);
		}
		// 그냥 구분선
		UE_LOG(LogTemp, Warning, TEXT("======================================================="));
	}
	UE_LOG(LogTemp, Warning, TEXT("Total Move Distance : %d"), totDist);
	UE_LOG(LogTemp, Warning, TEXT("Total Number of Event Occurrences : %d"), cntEvent);
}

//step 호출시 0~1 사이의 숫자를 랜덤으로 리턴
int32 AMyActor::step()
{
	const int32 minNum = 0;
	const int32 maxNum = 1;
	int32 randNum = FMath::RandRange(minNum, maxNum);

	return randNum;
}

//랜덤이벤트 1~100사이 숫자 리턴
int32 AMyActor::createEvent()
{
	//1~100 사이 숫자 랜덤 출력
	int32 randNum = FMath::RandRange(1, 100);

	return randNum;
}

