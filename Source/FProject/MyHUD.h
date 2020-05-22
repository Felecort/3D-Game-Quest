// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"



// СТРУКТУРА ДЛЯ ОТРИСОВКИ СООБЩЕНИЙ В HUD

struct Message
{
	// Переменная для сообщения
	FString message;

	// Переменная для времени отображения
	float time;

	// Переменная для цвета текста
	FColor color;

	// Передний и задний фон
	FColor frontColor;
	FColor backColor;

	// Псевдо-текстура лица NPC (И много других функций)
	UTexture2D* tex;
	
	/*
	Message()
	{
		// Время отображения сообщения
		time = 5.f;

		// Цвет текста
		color = FColor::White;
	}
	*/

	// Перегруженные функции 

	Message()
	{
		// Время отображения сообщения
		time = 5.f;

		// Цвет фона
		frontColor = FColor::White;
		backColor = FColor::Black;
	}



	Message(FString iMessage, float iTime, FColor iColor)
	{
		message = iMessage;
		time = iTime;
		color = iColor;
	}
	


	Message(FString iMessage, float iTime, FColor iFrontColor, FColor iBackColor)
	{
		message = iMessage;
		time = iTime;
		frontColor = iFrontColor;
		backColor = iBackColor;
		tex = 0;
	}



	Message(UTexture2D* iTex, FString iMessage, float iTime, FColor iFrontColor, FColor iBackColor)
	{
		tex = iTex;
		message = iMessage;
		time = iTime;
		frontColor = iFrontColor;
		backColor = iBackColor;
	}
};






// Макрос, необходимый для работы в UE Editor
UCLASS()
class FPROJECT_API AMyHUD : public AHUD
{
	// Макрос, необходимый для функционирования внутри UE
	GENERATED_UCLASS_BODY()

	// Настройки шрифта, используемого для отображения текста в HUD 
	// Сам шрифт устанавливается в BP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont) UFont* hudFont;
	
	// Массив доступных сообщений для отображения
	TArray<Message> messages;

	// Определение рарешения экрана(Активного окна)
	FVector2D dims;

	// Отображение в HUD, срабатывает раз за 1 кадр
	virtual void DrawHUD() override;

	// Функция для возможности добавления сообщений для отображения
	void addMessage(Message msg);

	// Отрисовка сообщений
	void DrawMessages();

	void DrawHealthbar();
};
