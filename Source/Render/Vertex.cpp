#include"Vertex.hpp"
void MountainTunnel::from_json(const nlohmann::json& json, MountainTunnel::Vertex& vertex)
{
	json.at("position").at("x").get_to<float>(vertex.position.x);
	json.at("position").at("y").get_to<float>(vertex.position.y);
	json.at("position").at("z").get_to<float>(vertex.position.z);
	json.at("textureUv").at("x").get_to<float>(vertex.textureUv.x);
	json.at("textureUv").at("y").get_to<float>(vertex.textureUv.y);
	json.at("normal").at("x").get_to<float>(vertex.normal.x);
	json.at("normal").at("y").get_to<float>(vertex.normal.y);
	json.at("normal").at("z").get_to<float>(vertex.normal.z);
}