#include "doctest.h"

#include "PhotoshopFile/PhotoshopFile.h"
#include "LayeredFile/LayeredFile.h"
#include "Macros.h"

#include <filesystem>

TEST_CASE("Read 300 DPI")
{
	using namespace NAMESPACE_PSAPI;

	std::filesystem::path psb_path = std::filesystem::current_path();
	psb_path += "\\documents\\DPI\\300dpi.psd";

	auto inputFile = File(psb_path);
	auto psDocumentPtr = std::make_unique<PhotoshopFile>();
	psDocumentPtr->read(inputFile);
	LayeredFile<bpp8_t> layeredFile = { std::move(psDocumentPtr) };

	// Get the DPI Profile we read from the PSD
	float readDPI = layeredFile.m_DotsPerInch;
	CHECK(readDPI == 300.0f);
}


TEST_CASE("Read 300.5 DPI")
{
	using namespace NAMESPACE_PSAPI;

	std::filesystem::path psb_path = std::filesystem::current_path();
	psb_path += "\\documents\\DPI\\300_point_5_dpi.psd";

	auto inputFile = File(psb_path);
	auto psDocumentPtr = std::make_unique<PhotoshopFile>();
	psDocumentPtr->read(inputFile);
	LayeredFile<bpp8_t> layeredFile = { std::move(psDocumentPtr) };

	// Get the DPI Profile we read from the PSD
	float readDPI = layeredFile.m_DotsPerInch;
	CHECK(readDPI == 300.5f);
}


TEST_CASE("Read 700 DPI")
{
	using namespace NAMESPACE_PSAPI;

	std::filesystem::path psb_path = std::filesystem::current_path();
	psb_path += "\\documents\\DPI\\700dpi.psd";

	auto inputFile = File(psb_path);
	auto psDocumentPtr = std::make_unique<PhotoshopFile>();
	psDocumentPtr->read(inputFile);
	LayeredFile<bpp8_t> layeredFile = { std::move(psDocumentPtr) };

	// Get the DPI Profile we read from the PSD
	float readDPI = layeredFile.m_DotsPerInch;
	CHECK(readDPI == 700.0f);
}