

#include "PRGame.h"
#include "NPCC.h"
#include "MyHUD.h"
#include "Avatar.h"

ANPCC::ANPCC(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

	//������������� � ������������ ����� ������ CreateDefaultSubobject
	//������ 8 ����� �� ��������� ���� ������
	ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("Proximity Sphere"));


	// ��������� �����
	ProxSphere->AttachTo(RootComponent);
	
	// ������ �����
	// �� ������������� � BP. (� ������?)
	ProxSphere->SetSphereRadius(172.f);

	// ��������� ���������
	// ����� �������� � BP
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPCC::Prox);
	NpcMessage = "Hello, this is a project at UE4"; 
}


// ��������, ������������ ��� ����������� �����
void ANPCC::Prox_Implementation(AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	// ���� ����������� � �� �������, �� ����� �� �������
	if (Cast<AAvatar>(OtherActor) == nullptr)
	{
		return;
	}
	// �����
	// �������������� � �������

	//��������� ������������, ���� ���������� 
	// �� ������ �� NPC <= R �����
	APlayerController* PController = GetWorld() -> GetFirstPlayerController();
	if (PController)
	{
		AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());
		hud->addMessage(Message(NpcMessage, 5.f, FColor::White));
	}

}