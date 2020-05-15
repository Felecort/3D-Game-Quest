// Fill out your copyright notice in the Description page of Project Settings.
/*
#pragma once

#include "GameFramework/Character.h"
#include "NPC.generated.h"

*/
/*
// Макрос, необходимый для работы в UE Editor
UCLASS()
class PRGAME_API ANPC : public ACharacter
{
	// Макрос, необходимый для функционирования внутри UE
	GENERATED_UCLASS_BODY()
	UPROPERTY() FString
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
	TSubobjectPtr<class USphereComponent> ProxSphere;
	// Работа с текстом (вместо string С++)
	//UPROPERTY() FString

	// Сообщение, которое выдаёт NPC
	// Доступно для редактрпоования в BP 
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
	// Это сообщение NPC, которое он должен сказать нам.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString NpcMessage;
	// Когда вы создаёте blueptint из этого класса, вы хотите, чтобы вы могли
	// редактировать это сообщение в blueprint,
	// вот почему у нас есть
	// свойства EditAnywhere и BlueprintReadWrite.
};*/