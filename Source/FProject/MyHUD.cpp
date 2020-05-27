
#include "FProject.h"
#include "MyHUD.h"
#include "Avatar.h"

//__1__
AMyHUD::AMyHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}


// РАБОТА С HUD

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	// Сохранение переменных Canvas->SizeY(Х) 
	// в переменные уровненовго класса
	dims.X = Canvas->SizeX;
	dims.Y = Canvas->SizeY;

	//DrawLine(200, 300, 400, 500, FLinearColor::Blue);
	// вызов функций
	DrawMessages();
	DrawHealthbar();

}


// ВЫВОД СООБЩЕНИЙ

void AMyHUD::DrawMessages()
{

	// Вызов функции суперкласса DrawHUD()
	Super::DrawHUD();

	// messages.Num() - количество сообщений
	for (int i = messages.Num() - 1; i >= 0; i--)
	{
		// Размеры фонового окна для сообщени
		float outputWidth, outputHeight = 10.f;
		
		// Получение ширины и высоты строки
		GetTextSize(messages[i].message, outputWidth, outputHeight, hudFont, 1.f);
		
		float messageH = outputHeight + 20.f;
		float x = 0.f
		float y = i * messageH;
		
		// Отрисовка чёрного фона
		DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, messageH);
		
		// Отрисовка текста
		DrawText(messages[i].message, messages[i].color, x + 10, y + 10, hudFont);
		
		// Сокрощаем время отображение на время прошеднее с последнего кадра  (GetWorld()->GetDeltaSeconds())
		messages[i].time -= GetWorld()->GetDeltaSeconds();
		
		// По истечении времени удаляем сообщение
		if (messages[i].time < 0)
		{
			// Удаление сообщения
			messages.RemoveAt(i);
		}
	}
}


void AMyHUD::addMessage(Message msg)
{
	messages.Add(msg);
}


// ОТРИСОВКА ШКАЛЫ ХП

void AMyHUD::DrawHealthbar()
{

	// Возвращене информации об объекте
	AAvatar* avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	// Натсройки размеров шкалы ХП
	float barWidth = 200 
	float barHeight = 50
	float barPad = 12
	float barMargin = 50

	// Получение процента оставшихся хит поинтов
	float percHp = (avatar->Hp) / (avatar->MaxHp);
	
	// FLinearColor - цвет RGBA
	DrawRect(FLinearColor(0, 0, 0, 1), Canvas->SizeX - barWidth - barPad
		- barMargin, Canvas->SizeY - barHeight - barPad - barMargin, barWidth +
		2 * barPad, barHeight + 2 * barPad);
	
	
	DrawRect(FLinearColor(1 - percHp, percHp, 0, 1), Canvas->SizeX -
		barWidth - barMargin, Canvas->SizeY - barHeight - barMargin,
		barWidth * percHp, barHeight);
}
