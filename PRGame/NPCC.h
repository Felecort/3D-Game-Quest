// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "NPCC.generated.h"

 // Макрос, необходимый для работы в UE Editor
UCLASS()
class PRGAME_API ANPCC : public ACharacter
{
	// Макрос, необходимый для функционирования внутри UE
	GENERATED_UCLASS_BODY()
		
		//Работа с текстом, прописанным в BP 
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		TSubobjectPtr<class USphereComponent> ProxSphere;
	// Работа с текстом (вместо string С++)


	//UPROPERTY() FString
	// Сообщение, которое выдаёт NPC
	// Доступно для редактрпоования в BP 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString NpcMessage;
	

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		//TSubobjectPtr<class USphereComponent> ProxSphere;
	
	
	// ANPC::Prox_Implementation, __не__ ANPC::Prox() - Тело функции(спасибо гуглу)
	// ибо BlueprintNativeEvent (что-то сложное и непонятное )
	
	// Сфера взаимодействия игрока и NPC
	
	// Объявление доп сферы объёма границ ProxSphere, которая осуществляет
	// Взаимодействие игрока и NPC
	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
		void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
			OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};