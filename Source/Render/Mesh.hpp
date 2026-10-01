#pragma once
#include<vector>
#include<cstddef>
#include"Render/VertexArray.hpp"
#include"Render/IndexBuffer.hpp"
#include"Render/VertexBuffer.hpp"
#include"Render/Vertex.hpp"
namespace MountainTunnel
{
	class Mesh
	{
	private:
		MountainTunnel::VertexArray _vertexArray;
		MountainTunnel::IndexBuffer _indexBuffer;
		MountainTunnel::VertexBuffer _vertexBuffer;
		int _count;
	public:
		Mesh(const std::vector<MountainTunnel::Vertex>& vertices, const std::vector<unsigned int>& indices);
		void Bind() const;
		void Draw() const;
	};
}