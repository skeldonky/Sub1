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

	start.Set(0.0f, 0.0f);  // ���� ��ǥ X�� Y�� 0���� ����
	totDist = 0;			// �� �̵��Ÿ��� 0���� ����

	// Ȯ�ο� �α� ���
	UE_LOG(LogTemp, Warning, TEXT("Start Position: X = %f, Y = %f"), start.X, start.Y);

	//�̵�
	move();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//�Ÿ����ϱ�
float AMyActor::distance(FVector2D first, FVector2D second)
{
	//�Ÿ����ϱ�
	double deltaX = second.X - first.X;
	double deltaY = second.Y - first.Y;

	//�����
	float result = sqrt(deltaX * deltaX + deltaY * deltaY);

	return result;
}

//move ȣ��� �̵�
void AMyActor::move()
{
	//�̺�Ʈ ī���ÿ�;
	int cntEvent = 0;

	//10���̵��̴� 10�� �ݺ�
	for (int i = 0; i < 10; i++)
	{
		//X, Y �̵��Ÿ� 0~1
		int32 XmovNum = 0;
		int32 YmovNum = 0;

		//�̵��Ÿ� 0 ���ִ°� ����
		while (true)
		{
			//X, Y �̵��Ÿ� 0~1
			XmovNum = step();
			YmovNum = step();

			//�� �� 0�̸� �ٽ� ���� �ϳ��� 1�̸� ������
			if (!(XmovNum == 0 && YmovNum == 0))
			{
				break;
			}
		}

		//�̵� ��ǥ Ȯ�ο�
		FVector2D beforeMov = start;	// �����̱� �� ��ǥ��
		FVector2D afterMov;				// ������ �� ��ǥ��

		start.X = start.X + XmovNum;
		start.Y = start.Y + YmovNum;

		afterMov = start;

		//�Ÿ� ���ϱ�
		float dist = distance(beforeMov, afterMov);

		//�� �̵��Ÿ� ����
		totDist += dist;

		//�̵� ��ǥ �α� ���
		UE_LOG(LogTemp, Warning, TEXT("Move Position: X = %f, Y = %f"), start.X, start.Y);
		//�̵� �Ÿ� �α� ���
		UE_LOG(LogTemp, Warning, TEXT("Move Distance: %f"), dist);

		const int32 minNum = 0;
		const int32 maxNum = 1;
		int32 randNum = FMath::RandRange(minNum, maxNum);

		//���� �̺�Ʈ 0 or 1 50%
		if (randNum == 0)
		{
			cntEvent++;
			int32 randEvenNum = createEvent();
			UE_LOG(LogTemp, Warning, TEXT("Random Event Message Number : %d"), randEvenNum);
		}
		// �׳� ���м�
		UE_LOG(LogTemp, Warning, TEXT("======================================================="));
	}
	UE_LOG(LogTemp, Warning, TEXT("Total Move Distance : %d"), totDist);
	UE_LOG(LogTemp, Warning, TEXT("Total Number of Event Occurrences : %d"), cntEvent);
}

//step ȣ��� 0~1 ������ ���ڸ� �������� ����
int32 AMyActor::step()
{
	const int32 minNum = 0;
	const int32 maxNum = 1;
	int32 randNum = FMath::RandRange(minNum, maxNum);

	return randNum;
}

//�����̺�Ʈ 1~100���� ���� ����
int32 AMyActor::createEvent()
{
	//1~100 ���� ���� ���� ���
	int32 randNum = FMath::RandRange(1, 100);

	return randNum;
}

