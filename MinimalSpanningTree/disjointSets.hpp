#ifndef BOOST_DISJOINT_SETS_HPP
#define BOOST_DISJOINT_SETS_HPP

---------------------------------------------


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Data structure to store graph edges
struct Edge {
	int src, dest, weight;
};

// Class to represent a disjoint set
class DisjointSet
{
	unordered_map<int, int> parent;
public:
	// perform MakeSet operation
	void makeSet(int N)
	{
		// create N disjoint sets (one for each vertex)
		for (int i = 0; i < N; i++)
			parent[i] = i;
	}

	// Find the root of the set in which element k belongs
	int Find(int k)
	{
		// if k is root
		if (parent[k] == k)
			return k;

		// recur for parent until we find root
		return Find(parent[k]);
	}

	// Perform Union of two subsets
	void Union(int a, int b)
	{
		// find root of the sets in which elements
		// x and y belongs
		int x = Find(a);
		int y = Find(b);

		parent[x] = y;
	}
};

// construct MST using Kruskal's algorithm
vector<Edge> KruskalAlgo(vector<Edge> edges, int N)
{
	// stores edges present in MST
	vector<Edge> MST;

	// initialize DisjointSet class
	DisjointSet ds;

	// create singleton set for each element of universe
	ds.makeSet(N);

	// MST contains exactly V-1 edges
	while (MST.size() != N - 1)
	{
		// consider next edge with minimum weight from the graph
		Edge next_edge = edges.back();
		edges.pop_back();
		
		// find root of the sets to which two endpoint
		// vertices of next_edge belongs	
		int x = ds.Find(next_edge.src);
		int y = ds.Find(next_edge.dest);

		// if both endpoints have different parents, they belong to
		// different connected components and can be included in MST
		if (x != y)
		{
			MST.push_back(next_edge);
			ds.Union(x, y);
		}
	}
	return MST;
}

// Comparison object to be used to order the Edges
struct compare
{
	inline bool operator() (Edge const &a, Edge const &b)
	{
		return (a.weight > b.weight);
	}
};

// main function
int main()
{
	// vector of graph edges as per above diagram.
	vector<Edge> edges =
	{
		// (u, v, w) tiplet represent undirected edge from
		// vertex u to vertex v having weight w
		{ 0, 1, 7 }, { 1, 2, 8 }, { 0, 3, 5 }, { 1, 3, 9 },
		{ 1, 4, 7 }, { 2, 4, 5 }, { 3, 4, 15 }, { 3, 5, 6 },
		{ 4, 5, 8 }, { 4, 6, 9 }, { 5, 6, 11 }
	};
	
	// sort edges by increasing weight
	sort(edges.begin(), edges.end(), compare());

	// Number of vertices in the graph
	int N = 7;

	// construct graph
	vector<Edge> e = KruskalAlgo(edges, N);

	for (Edge &edge: e)
		cout << "(" << edge.src << ", " << edge.dest << ", "
			<< edge.weight << ")" << endl;

	return 0;
}















----------------------------------------------------

#include <vector>
// #include <boost/graph/properties.hpp>
// #include <boost/pending/detail/disjoint_sets.hpp>

namespace boost {

  struct find_with_path_halving {
    template <class ParentPA, class Vertex>
    Vertex operator()(ParentPA p, Vertex v) { 
      return detail::find_representative_with_path_halving(p, v);
    }
  };

  struct find_with_full_path_compression {
    template <class ParentPA, class Vertex>
    Vertex operator()(ParentPA p, Vertex v){
      return detail::find_representative_with_full_compression(p, v);
    }
  };

  // This is a generalized functor to provide disjoint sets operations
  // with "union by rank" and "path compression".  A disjoint-set data
  // structure maintains a collection S={S1, S2, ..., Sk} of disjoint
  // sets. Each set is identified by a representative, which is some
  // member of of the set. Sets are represented by rooted trees. Two
  // heuristics: "union by rank" and "path compression" are used to
  // speed up the operations.

  // Disjoint Set requires two vertex properties for internal use.  A
  // RankPA and a ParentPA. The RankPA must map Vertex to some Integral type
  // (preferably the size_type associated with Vertex). The ParentPA
  // must map Vertex to Vertex.
  template <class RankPA, class ParentPA,
    class FindCompress = find_with_full_path_compression
    >
  class disjoint_sets {
    typedef disjoint_sets self;
    
    inline disjoint_sets() {}
  public:
    inline disjoint_sets(RankPA r, ParentPA p) 
      : rank(r), parent(p) {}

    inline disjoint_sets(const self& c) 
      : rank(c.rank), parent(c.parent) {}
    
    // Make Set -- Create a singleton set containing vertex x
    template <class Element>
    inline void make_set(Element x)
    {
      put(parent, x, x);
      typedef typename property_traits<RankPA>::value_type R;
      put(rank, x, R());
    }
    
    // Link - union the two sets represented by vertex x and y
    template <class Element>
    inline void link(Element x, Element y)
    {
      detail::link_sets(parent, rank, x, y, rep);
    }
    
    // Union-Set - union the two sets containing vertex x and y 
    template <class Element>
    inline void union_set(Element x, Element y)
    {
      link(find_set(x), find_set(y));
    }
    
    // Find-Set - returns the Element representative of the set
    // containing Element x and applies path compression.
    template <class Element>
    inline Element find_set(Element x)
    {
      return rep(parent, x);
    }

    template <class ElementIterator>
    inline std::size_t count_sets(ElementIterator first, ElementIterator last)
    {
      std::size_t count = 0;  
      for ( ; first != last; ++first)
      if (get(parent, *first) == *first)
        ++count;
      return count;
    }

    template <class ElementIterator>
    inline void normalize_sets(ElementIterator first, ElementIterator last)
    {
      for (; first != last; ++first) 
        detail::normalize_node(parent, *first);
    }    
    
    template <class ElementIterator>
    inline void compress_sets(ElementIterator first, ElementIterator last)
    {
      for (; first != last; ++first) 
        detail::find_representative_with_full_compression(parent, *first);
    }    
  protected:
    RankPA rank;
    ParentPA parent;
    FindCompress rep;
  };


  

  template <class ID = identity_property_map,
            class InverseID = identity_property_map,
            class FindCompress = find_with_full_path_compression
            >
  class disjoint_sets_with_storage
  {
    typedef typename property_traits<ID>::value_type Index;
    typedef std::vector<Index> ParentContainer;
    typedef std::vector<unsigned char> RankContainer;
  public:
    typedef typename ParentContainer::size_type size_type;

    disjoint_sets_with_storage(size_type n = 0,
                               ID id_ = ID(),
                               InverseID inv = InverseID())
      : id(id_), id_to_vertex(inv), rank(n, 0), parent(n)
    {
      for (Index i = 0; i < n; ++i)
        parent[i] = i;
    }
    // note this is not normally needed
    template <class Element>
    inline void 
    make_set(Element x) {
      parent[x] = x;
      rank[x]   = 0;
    }
    template <class Element>
    inline void 
    link(Element x, Element y)
    {
      extend_sets(x,y);
      detail::link_sets(&parent[0], &rank[0], 
                        get(id,x), get(id,y), rep);
    }
    template <class Element>
    inline void 
    union_set(Element x, Element y) {
      Element rx = find_set(x);
      Element ry = find_set(y);
      link(rx, ry);
    }
    template <class Element>
    inline Element find_set(Element x) {
      return id_to_vertex[rep(&parent[0], get(id,x))];
    }

    template <class ElementIterator>
    inline std::size_t count_sets(ElementIterator first, ElementIterator last)
    {
      std::size_t count = 0;  
      for ( ; first != last; ++first)
      if (parent[*first] == *first)
        ++count;
      return count;
    }

    template <class ElementIterator>
    inline void normalize_sets(ElementIterator first, ElementIterator last)
    {
      for (; first != last; ++first) 
        detail::normalize_node(&parent[0], *first);
    }    
    
    template <class ElementIterator>
    inline void compress_sets(ElementIterator first, ElementIterator last)
    {
      for (; first != last; ++first) 
        detail::find_representative_with_full_compression(&parent[0],
                                                          *first);
    }    

    const ParentContainer& parents() { return parent; }

  protected:

    template <class Element>
    inline void 
    extend_sets(Element x, Element y)
    {
      Index needed = get(id,x) > get(id,y) ? get(id,x) + 1 : get(id,y) + 1;
      if (needed > parent.size()) {
        rank.insert(rank.end(), needed - rank.size(), 0);
        for (Index k = parent.size(); k < needed; ++k)
        parent.push_back(k);
      } 
    }

    ID id;
    InverseID id_to_vertex;
    RankContainer rank;
    ParentContainer parent;
    FindCompress rep;
  };

} // namespace boost

#endif // BOOST_DISJOINT_SETS_HPP