
#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

struct Message
{
	FString message;
	float time;
	FColor color;
	FColor frontColor;
	FColor backColor;
	UTexture2D* tex;

	Message()
	{
		// Время отображения по умолчанию
		time = 5.f;

		// Установка цветов
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

UCLASS()
class PRGAME_API AMyHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

		// Шрифт, используемый для изображения текста в HUD
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont) UFont* hudFont;

	// Массив сообщений для отображения
	TArray<Message> messages;
	
	// Цвета экрана
	FVector2D dims;
	
	// Отображение в HUD, срабатывает раз за 1 кадр
	virtual void DrawHUD() override;

	// Функция для возможности добавлять сообщение для отображения
	void addMessage(Message msg);

	void DrawMessages();
};

