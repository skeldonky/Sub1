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

	start.Set(0.0f, 0.0f);  // X�� Y�� 0���� ����

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

//move ȣ��� �̵�
void AMyActor::move()
{
	//10���̵��̴� 10�� �ݺ�
	for (int i = 0; i < 10; i++)
	{
		//X, Y �̵��Ÿ� 0~1
		int32 XmovNum = step();
		int32 YmovNum = step();

		start.X = start.X + XmovNum;
		start.Y = start.Y + YmovNum;

		UE_LOG(LogTemp, Warning, TEXT("Move Position: X = %f, Y = %f"), start.X, start.Y);
	}
}

//step ȣ��� 0~1 ������ ���ڸ� �������� ���
int32 AMyActor::step()
{
	const int32 minNum = 0;
	const int32 maxNum = 1;
	int32 randNum = FMath::RandRange(minNum, maxNum);

	return randNum;
}

