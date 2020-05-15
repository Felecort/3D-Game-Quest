// Fill out your copyright notice in the Description page of Project Settings.

#include "PRGame.h"
#include "MyHUD.h"


AMyHUD::AMyHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

/*
// Функция отображения сообщений
void AMyHUD::DrawHUD()
{
	Super::DrawHUD();
	
	//Выполняем итерацию в обратном порядке, чтобы при удалении
	//пункта во время итерации не возникало проблем
	
	for (int c = messages.Num() - 1; c >= 0; c--)
	{

		// Фоновое окно для сообщения с указанным размером
		float outputWidth, outputHeight, pad = 10.f;
		GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.f);
		float messageH = outputHeight + 2.f * pad;
		float x = 0.f, y = c * messageH;
		
		// Чёрный фон
		DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, messageH);
		
		// Отображение сообщения используя hudFont
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);
		
		
		//Cокращаем время отображения на время прошедшее
		//с последнего кадра.
		
		messages[c].time -= GetWorld()->GetDeltaSeconds();
		
		// Удаление сообщения по истечению времени
		if (messages[c].time < 0)
		{
			messages.RemoveAt(c);
		}
	}
}*/


void AMyHUD::DrawMessages()
{
	/*
	Выполняем итерацию в обратном порядке, чтобы при удалении
	пункта во время итерации не возникало проблем
	*/
	for (int c = messages.Num() - 1; c >= 0; c--)
	{
		// Фоновое окно для сообщения с указанным размером
		float ow, oh, pad = 10.f;
		GetTextSize(messages[c].message, ow, oh, hudFont, 1.f);

		float messageH = oh + 2 * pad;
		float x = 0, y = c * messageH;

		// Отрисовка фона 
		if (messages[c].tex)
		{

			DrawTexture(messages[c].tex, x, y, messageH, messageH, 0, 0, 1, 1);
		}
		else
		{
			DrawRect(FLinearColor::Red, x, y, messageH, messageH);
		}
		x += messageH;

		DrawRect(messages[c].backColor, x, y, Canvas->SizeX, messageH);
		
		// Отображение сообщения используя hudFont
		DrawText(messages[c].message, messages[c].frontColor, x + pad, y + pad, hudFont);

		
		/*
		Cокращаем время отображения на время прошедшее
		с последнего кадра.
		*/
		messages[c].time -= GetWorld()->GetDeltaSeconds();

		if (messages[c].time < 0)
		{
			messages.RemoveAt(c);
		}
	}
}


void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	// Сохранение переменных в переменные уровневого класса
	dims.X = Canvas->SizeX;
	dims.Y = Canvas->SizeY;

	DrawMessages();
	//DrawHealthbar(); не работает:(
}




void AMyHUD::addMessage(Message msg)
{
	messages.Add(msg);
}