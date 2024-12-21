#pragma once

#include "StaticMeshInstance.h"
#include "RenderTransform.h"

class MaterialTexture;
class ModelResource;

class EnvironmentModel
{
public:
	EnvironmentModel() = default;
	~EnvironmentModel() = default;

	void SetWorldMatrix(Math::Matrix* componentMatrix) { m_worldMatrix = componentMatrix; }

	bool ReadEnvironmentMeshFromFBX(std::string_view filePath);
	bool ReadEnvironmentTextureFromDDS(std::wstring filePath);
	bool ReadIBLDiffuseTextureFromDDS(std::wstring filePath);
	bool ReadIBLSpecularTextureFromDDS(std::wstring filePath);
	bool ReadIBLBRDFTextureFromDDS(std::wstring filePath);


	std::shared_ptr<ModelResource>		m_SceneResource;
	std::shared_ptr<MaterialTexture>	m_EnvironmentTextureResource;
	std::shared_ptr<MaterialTexture>	m_IBLDiffuseTextureResource;
	std::shared_ptr<MaterialTexture>	m_IBLSpecularTextureResource;
	std::shared_ptr<MaterialTexture>	m_IBLBRDFTextureResource;
	StaticMeshInstance					m_MeshInstance;

	std::string m_SceneFilePath; // BeginPlay���� �ε�
	std::wstring m_EnvironmentTexturePath; // BeginPlay���� �ε�
	std::wstring m_IBLSpecularTexturePath; // BeginPlay���� �ε�
	std::wstring m_IBLDiffuseTexturePath; // BeginPlay���� �ε�
	std::wstring m_IBLBRDFTexturePath; // BeginPlay���� �ε�

	Math::Matrix* m_worldMatrix = nullptr;	// EnvironmentComponent�� matrix ����
};
