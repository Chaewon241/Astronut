#pragma once

class Mesh;
class Material;
class Bone;
struct CB_MatrixPalette;

class SkeletalMeshInstance
{
public:
	SkeletalMeshInstance();
	~SkeletalMeshInstance();

public:
	Mesh* m_pMeshResource = nullptr;
	Material* m_pMaterial = nullptr;
	Math::Matrix* m_pNodeWorldTransform = nullptr;		// SkeletalMesh�� ��������� ���� ����� ������
	std::vector<Math::Matrix*>		m_BoneReferences;	// ���� �ش�Ǵ� ���MATRIX�� �����͸� �����Ѵ�.

public:
	void Create(Mesh* pMeshResource, Bone* pRootNode, Material* pMaterial);
	void BindingMaterial(Material* pMaterial);
	void UpdateMatrixPallete(Math::Matrix* MatrixPalettePtr);
	virtual void Render(ID3D11DeviceContext* deviceContext);
};
