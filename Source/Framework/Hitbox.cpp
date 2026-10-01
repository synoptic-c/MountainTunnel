#include"Hitbox.hpp"
void MountainTunnel::from_json(const nlohmann::json& json, MountainTunnel::Hitbox& hitbox)
{
	json.at("range").at("x").get_to(hitbox.range.x);
	json.at("range").at("y").get_to(hitbox.range.y);
	json.at("range").at("z").get_to(hitbox.range.z);
}