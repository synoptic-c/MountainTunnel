#include"Mesh.hpp"
MountainTunnel::Mesh::Mesh(const std::vector<MountainTunnel::Vertex>& vertices, const std::vector<unsigned int>& indices)
{
	_vertexBuffer.NamedBufferStorage(sizeof(MountainTunnel::Vertex) * vertices.size(), vertices.data(), GL_DYNAMIC_STORAGE_BIT);
	_indexBuffer.NamedBufferStorage(sizeof(unsigned int) * indices.size(), indices.data(), GL_DYNAMIC_STORAGE_BIT);
	_vertexArray.VertexArrayAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
	_vertexArray.VertexArrayAttribFormat(1, 2, GL_FLOAT, GL_FALSE, offsetof(MountainTunnel::Vertex, MountainTunnel::Vertex::textureUv));
	_vertexArray.VertexArrayAttribFormat(2, 3, GL_FLOAT, GL_FALSE, offsetof(MountainTunnel::Vertex, MountainTunnel::Vertex::normal));
	_vertexArray.VertexArrayAttribBinding(0, 0);
	_vertexArray.VertexArrayAttribBinding(1, 0);
	_vertexArray.VertexArrayAttribBinding(2, 0);
	_vertexArray.VertexArrayVertexBuffer(0, _vertexBuffer.GetVertexBuffer(), 0, sizeof(MountainTunnel::Vertex));
	_vertexArray.EnableVertexArrayAttrib(0);
	_vertexArray.EnableVertexArrayAttrib(1);
	_vertexArray.EnableVertexArrayAttrib(2);
	_vertexArray.VertexArrayElementBuffer(_indexBuffer.GetIndexBuffer());
	_count = indices.size();
}
void MountainTunnel::Mesh::Bind() const
{
	_vertexArray.Bind();
}
void MountainTunnel::Mesh::Draw() const
{
	_vertexArray.DrawElements(_count);
}