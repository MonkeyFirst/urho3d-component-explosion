# urho3d-component-explosion
urho3d-component-explosion

video : https://www.youtube.com/watch?v=qwZfQxXa3-U

usage:
#include "CustomLogic.h"
CustomLogic::RegisterObject(context);

Node* node = scene_->GetChild("Boom", true);
node->CreateComponent<CustomLogic>();