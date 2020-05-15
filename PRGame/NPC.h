// Fill out your copyright notice in the Description page of Project Settings.
/*
#pragma once

#include "GameFramework/Character.h"
#include "NPC.generated.h"

*/
/*
// ������, ����������� ��� ������ � UE Editor
UCLASS()
class PRGAME_API ANPC : public ACharacter
{
	// ������, ����������� ��� ���������������� ������ UE
	GENERATED_UCLASS_BODY()
	UPROPERTY() FString
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
	TSubobjectPtr<class USphereComponent> ProxSphere;
	// ������ � ������� (������ string �++)
	//UPROPERTY() FString

	// ���������, ������� ����� NPC
	// �������� ��� ��������������� � BP 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	FString NpcMessage;

	
	
};*/
/*
UCLASS()
class PRGAME_API ANPC : public ACharacter
{
	GENERATED_UCLASS_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		TSubobjectPtr<class USphereComponent> ProxSphere;
	// ��� ��������� NPC, ������� �� ������ ������� ���.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString NpcMessage;
	// ����� �� ������� blueptint �� ����� ������, �� ������, ����� �� �����
	// ������������� ��� ��������� � blueprint,
	// ��� ������ � ��� ����
	// �������� EditAnywhere � BlueprintReadWrite.
};*/