#include "Common.h"
#include "CustomLogic.h"

/// Construct.
CustomLogic::CustomLogic(Context* context) : LogicComponent(context)
{
	SetUpdateEventMask(USE_FIXEDUPDATE | USE_UPDATE);
}

void CustomLogic::RegisterObject(Context* context) 
{
	context->RegisterFactory<CustomLogic>();
}

void CustomLogic::Start() 
{
	StaticModel* model = GetNode()->GetComponent<StaticModel>();
	mat = model->GetMaterial(0);
	mat->SetScene(GetScene());

#define ANIMATION(V) SharedPtr<ValueAnimation> V = SharedPtr<ValueAnimation>(new ValueAnimation(context_));

	//SharedPtr<ValueAnimation> animSize = SharedPtr<ValueAnimation>(new ValueAnimation(context_));
	
	ANIMATION(animSize);
	animSize->SetKeyFrame(0.0f, Vector3::ONE * 0.1f);
	animSize->SetKeyFrame(1.0f, Vector3::ONE * 2.0f);
	animSize->SetKeyFrame(4.0f, Vector3::ONE * 3.0f);

	GetNode()->SetAttributeAnimation("Scale", animSize);
	GetNode()->SetScene(GetScene());

	ANIMATION(animClipRange);
	animClipRange->SetKeyFrame(0.0f, 1.0f);
	animClipRange->SetKeyFrame(1.0f, 1.0f);
	animClipRange->SetKeyFrame(4.0f, 0.8f);
	
	mat->SetShaderParameterAnimation("ClipRange", animClipRange);

	ANIMATION(animRange);
	animRange->SetKeyFrame(0.0f, Vector2(0.0f, 1.3f));
	animRange->SetKeyFrame(1.0f, Vector2(0.0f, 1.3f));
	animRange->SetKeyFrame(4.0f, Vector2(1.0f, 1.3f));
	mat->SetShaderParameterAnimation("Range", animRange);

	ANIMATION(animDisplace);
	animDisplace->SetKeyFrame(0.0f, -1.0f);
	animDisplace->SetKeyFrame(4.0f, 5.0f);
	mat->SetShaderParameterAnimation("Displacement", animDisplace);


#undef ANIMATION

	
	
}

void CustomLogic::Update(float timeStep) 
{

	
}

void CustomLogic::FixedUpdate(float timeStep)
{


	if (!mat) return;

#define  M_PI   3.14159265358979323846S

	float loopPlayTime = 4.0f;
	Time* time = GetSubsystem<Time>();
	float elapsed = time->GetElapsedTime();


	float r = sinf((elapsed / loopPlayTime) * (2 * M_PI)) * 0.5f + 0.25f;
	float g = sinf((elapsed / loopPlayTime + 0.33333333f) * 2 * M_PI) * 0.5f + 0.25f;
	float b = sinf((elapsed / loopPlayTime + 0.66666666f) * 2 * M_PI) * 0.5f + 0.25f;
	float invNorm = 1.0f / (r + g + b);

	//r *= invNorm;
	//g *= invNorm;
	//b *= invNorm;

	float d = sin(elapsed / (loopPlayTime / 4.0f)) * 4;

	Vector3 rgb(r, g, b);
	rgb.Normalize();
	mat->SetShaderParameter("ChannelFactor", rgb);
	
	//mat->SetShaderParameter("Displacement", d);
	
	
	//mat->SetShaderParameter("Range", Vector2(0.0f, 1.0f)); // control ramp texture color
	//mat->SetShaderParameter("ClipRange", 1.0f);

	

}