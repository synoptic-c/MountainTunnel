#include"Translate.hpp"
void MountainTunnel::from_json(const nlohmann::json& json, MountainTunnel::Translate& translate)
{
	json.at("position").at("x").get_to<float>(translate.position.x);
	json.at("position").at("y").get_to<float>(translate.position.y);
	json.at("position").at("z").get_to<float>(translate.position.z);
	json.at("scale").at("x").get_to<float>(translate.scale.x);
	json.at("scale").at("y").get_to<float>(translate.scale.y);
	json.at("scale").at("z").get_to<float>(translate.scale.z);
	json.at("axis").at("x").get_to<float>(translate.axis.x);
	json.at("axis").at("y").get_to<float>(translate.axis.y);
	json.at("axis").at("z").get_to<float>(translate.axis.z);
	json.at("angle").get_to<float>(translate.angle);
}