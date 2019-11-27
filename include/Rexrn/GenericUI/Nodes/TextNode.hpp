#pragma once

#include <Rexrn/GenericUI/Node.hpp>

#include <string>

namespace rexrn
{
namespace gui
{

/// <summary>A node that contains text.</summary>
class TextNode
	: public Node
{
public:
	TextNode() = default;
	TextNode(std::string text_)
		: text( std::move( text_) )
	{
	}
	
	std::string text;
};

}
}