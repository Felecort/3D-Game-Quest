
#include "FProject.h"
#include "MyHUD.h"
#include "Avatar.h"

AMyHUD::AMyHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	/*
	void AMyHUD::DrawWidgets()

	// Отрисовка граф элементов
	{
		for (int c = 0; c < widgets.Num(); c++)
		{
			DrawTexture(widgets[c].icon.tex, widgets[c].pos.X, widgets[c].pos.Y, widgets[c].size.X,
				widgets[c].size.Y, 0, 0, 1, 1);
			DrawText(widgets[c].icon.name, FLinearColor::Yellow, widgets[c].pos.X, widgets[c].pos.Y,
				hudFont, .6f, false);
		}
	}
	*/

}






// Отладка кода
/*
void AMyHUD::DrawHUD()
{
	// Вызов функции суперкласса DrawHUD()
	Super::DrawHUD();

	// Отрисовка линии с заданным цветом
	DrawLine(200, 300, 400, 500, FLinearColor::Blue);
	
	// Отрисовка текста
	DrawText("Unreal приветствует вас!", FVector2D(0, 0), hudFont, FVector2D(1, 1), FColor::White);
}
*/

// РАБОТА С HUD

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	// Сохранение переменных Canvas->SizeY(Х) 
	// в переменные уровненовго класса
	dims.X = Canvas->SizeX;
	dims.Y = Canvas->SizeY;

	//DrawLine(200, 300, 400, 500, FLinearColor::Blue);
	DrawMessages();
	DrawHealthbar();


	//Super::DrawHUD();

	//DrawWidgets();



}


// ВЫВОД СООБЩЕНИЙ

void AMyHUD::DrawMessages()
{

	// Вызов функции суперкласса DrawHUD()
	Super::DrawHUD();


	for (int c = messages.Num() - 1; c >= 0; c--)
	{
		// Размеры фонового окна для сообщени
		float outputWidth, outputHeight, pad = 10.f;
		GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.f);
		float messageH = outputHeight + 2.f * pad;
		float x = 0.f, y = c * messageH;
		
		// Отображение чёрного фона
		DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, messageH);
		
		// Отрисовка изображения, используя hudFont
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);
		
		// Сокрощаем время отображение на время прошеднее с последнего кадра  (GetWorld()->GetDeltaSeconds())
		messages[c].time -= GetWorld()->GetDeltaSeconds();
		
		// По истечении времени удаляем сообщение
		if (messages[c].time < 0)
		{
			// Удаление сообщения
			messages.RemoveAt(c);
		}
	}
}

/*
void AMyHUD::DrawMessages()
{
	Super::DrawHUD();
	// выполняем итерацию задом наперёд, так что если мы удаляем
	// пункт во время итерации, не возникнет никаких проблем
	for (int c = messages.Num() - 1; c >= 0; c--)
	{
		// изображаем фоновое окно для сообщения
		// нужного размера
		float outputWidth, outputHeight, pad = 10.f;
		GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont,
			1.f);
		float messageH = outputHeight + 2.f * pad;
		float x = 0.f, y = c * messageH;
		// чёрный фон
		DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, messageH);
		// изображаем наше сообщение используя hudFont
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad,
			hudFont);
		// сокращаем время отображения на время прошедшее
		// с последнего кадра.
		messages[c].time -= GetWorld()->GetDeltaSeconds();
		// если время сообщения вышло, удаляем его
		if (messages[c].time < 0)
		{
			messages.RemoveAt(c);
		}
	}
}
*/



void AMyHUD::addMessage(Message msg)
{
	messages.Add(msg);
}


// ОТРИСОВКА ШКАЛЫ ХП

void AMyHUD::DrawHealthbar()
{
	// Отрисовка хп
	AAvatar* avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	// Натсройки размеров шкалы ХП
	float barWidth = 200, barHeight = 50, barPad = 12, barMargin = 50;
	float percHp = avatar->Hp / avatar->MaxHp;
	
	
	DrawRect(FLinearColor(0, 0, 0, 1), Canvas->SizeX - barWidth - barPad
		- barMargin, Canvas->SizeY - barHeight - barPad - barMargin, barWidth +
		2 * barPad, barHeight + 2 * barPad);
	
	
	DrawRect(FLinearColor(1 - percHp, percHp, 0, 1), Canvas->SizeX -
		barWidth - barMargin, Canvas->SizeY - barHeight - barMargin,
		barWidth * percHp, barHeight);
}



/*


void AMyHUD::addWidget(Widget widget)
{
	// Поиск коорд граф элемента
	FVector2D start(200, 200), pad(12, 12);
	widget.size = FVector2D(100, 100);
	widget.pos = start;
	
	// Вычиление положения
	for (int c = 0; c < widgets.Num(); c++)
	{

		widget.pos.X += widget.size.X + pad.X;

		if (widget.pos.X + widget.size.X > dims.X)
		{
			widget.pos.X = start.X;
			widget.pos.Y += widget.size.Y + pad.Y;
		}
	}
	widgets.Add(widget);
}


*/