# urho3d-component-explosion
urho3d-component-explosion

usage:
#include "CustomLogic.h"
CustomLogic::RegisterObject(context);

Node* node = scene_->GetChild("Boom", true);
node->CreateComponent<CustomLogic>();