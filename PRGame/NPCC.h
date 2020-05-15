// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "NPCC.generated.h"

 // ������, ����������� ��� ������ � UE Editor
UCLASS()
class PRGAME_API ANPCC : public ACharacter
{
	// ������, ����������� ��� ���������������� ������ UE
	GENERATED_UCLASS_BODY()
		
		//������ � �������, ����������� � BP 
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		TSubobjectPtr<class USphereComponent> ProxSphere;
	// ������ � ������� (������ string �++)


	//UPROPERTY() FString
	// ���������, ������� ����� NPC
	// �������� ��� ��������������� � BP 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString NpcMessage;
	

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		//TSubobjectPtr<class USphereComponent> ProxSphere;
	
	
	// ANPC::Prox_Implementation, __��__ ANPC::Prox() - ���� �������(������� �����)
	// ��� BlueprintNativeEvent (���-�� ������� � ���������� )
	
	// ����� �������������� ������ � NPC
	
	// ���������� ��� ����� ������ ������ ProxSphere, ������� ������������
	// �������������� ������ � NPC
	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
		void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
			OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};