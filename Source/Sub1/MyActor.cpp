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

	start.Set(0.0f, 0.0f);  // X와 Y를 0으로 설정

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

//move 호출시 이동
void AMyActor::move()
{
	//10번이동이니 10번 반복
	for (int i = 0; i < 10; i++)
	{
		//X, Y 이동거리 0~1
		int32 XmovNum = step();
		int32 YmovNum = step();

		start.X = start.X + XmovNum;
		start.Y = start.Y + YmovNum;

		UE_LOG(LogTemp, Warning, TEXT("Move Position: X = %f, Y = %f"), start.X, start.Y);
	}
}

//step 호출시 0~1 사이의 숫자를 랜덤으로 출력
int32 AMyActor::step()
{
	const int32 minNum = 0;
	const int32 maxNum = 1;
	int32 randNum = FMath::RandRange(minNum, maxNum);

	return randNum;
}

