// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class SUB1_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	FVector2D start;
	int32 evCnt;
	int totDist;

	// Sets default values for this actor's properties
	AMyActor();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//�� �Լ��� ��������
	//�Ÿ� Ȯ��
	float distance(FVector2D first, FVector2D second);

	//�̵�
	void move();

	//���� ���� 0~1
	int32 step();

};
