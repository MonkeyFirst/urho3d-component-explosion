#pragma once

class CustomLogic : public LogicComponent
{
	OBJECT(CustomLogic);
public:
	

	CustomLogic(Context* context);
	virtual void Start();
	void Update(float timeStep);
	void FixedUpdate(float timeStep);

	static void RegisterObject(Context* context);

	SharedPtr<Material> mat;



};