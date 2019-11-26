#pragma once

#include <Rexrn/GenericUI/Node.hpp>

#include <vector>
#include <memory>

namespace rexrn
{
namespace gui
{

/// <summary>Basic UI tree object that can be a parent to nodes.</summary>
class Element
	: public Node
{
public:
	/// <summary>Appends a child.</summary>
	/// <param name="node_">The child node.</param>
	void appendChild( std::unique_ptr<Node> node_ );

	/// <summary>Removes every child.</summary>
	/// <param name="releaseMemory_">Whether to release memory used by the children container.</param>
	void clearChildren(bool releaseMemory_ = true)
	{
		_children.clear();
		if (releaseMemory_)
			_children.shrink_to_fit();
	}

	/// <summary>Releases children.</summary>
	auto releaseChildren()
	{
		auto ret = std::move(_children);
		this->clearChildren(); // TODO: check if this is necessary.
		return ret;
	}

	/// <summary>Returns the children container (by cref).</summary>
	auto const& getChildren() const
	{
		return _children;
	}
protected:
	std::vector< std::shared_ptr<Node> > _children;
};

}
}