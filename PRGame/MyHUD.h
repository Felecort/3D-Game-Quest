
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
		// ����� ����������� �� ���������
		time = 5.f;

		// ��������� ������
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

		// �����, ������������ ��� ����������� ������ � HUD
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont) UFont* hudFont;

	// ������ ��������� ��� �����������
	TArray<Message> messages;
	
	// ����� ������
	FVector2D dims;
	
	// ����������� � HUD, ����������� ��� �� 1 ����
	virtual void DrawHUD() override;

	// ������� ��� ����������� ��������� ��������� ��� �����������
	void addMessage(Message msg);

	void DrawMessages();
};

