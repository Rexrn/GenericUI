#include <Rexrn/GenericUI/Views/ButtonView.hpp>

#include <Rexrn/GenericUI/Element.hpp>
#include <Rexrn/GenericUI/Nodes/TextNode.hpp>

#include <cassert>
#include <stdexcept>

namespace rexrn
{
namespace gui
{

//////////////////////////////////////////////////////////////
void ButtonView::setText(std::string text_)
{
	assert(viewedElement);

	viewedElement->clearChildren(true);
	viewedElement->appendChild( std::make_unique<TextNode>( std::move(text_) ) );
}

//////////////////////////////////////////////////////////////
TextNode* ButtonView::findTextNode() const
{
	assert(viewedElement);

	auto const& children = viewedElement->getChildren();

	// Exactly one child is required.
	if (children.size() != 1)
		return nullptr;
	return dynamic_cast<TextNode*>(children[0].get());
}

//////////////////////////////////////////////////////////////
std::string ButtonView::getText() const
{
	assert(viewedElement);

	if ( auto tn = this->findTextNode() )
		return tn->text;
	else
		throw std::runtime_error("text node could not be found");
}

}
}