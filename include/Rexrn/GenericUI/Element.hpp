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
	using ChildrenContainer = std::vector< std::shared_ptr<Node> >;

	/// <summary>Appends a child.</summary>
	/// <param name="node_">The child node.</param>
	void appendChild( std::unique_ptr<Node> node_ );

	/// <summary>Removes every child.</summary>
	/// <param name="releaseMemory_">Whether to release memory used by the children container.</param>
	void clearChildren(bool releaseMemory_ = true);

	/// <summary>Releases children.</summary>
	ChildrenContainer releaseChildren();

	/// <summary>Determines whether element is parent of the specified node.</summary>
	/// <param name="node_">The tested node.</param>
	/// <param name="recursive_">Whether to check recursively or not.</param>
	bool isParentOf(Node const& node_, bool recursive_ = false) const;

	/// <summary>Returns the children container (by cref).</summary>
	ChildrenContainer const& getChildren() const;
protected:
	ChildrenContainer _children;
};

}
}