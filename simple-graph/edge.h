#ifndef _EDGE_CLASS
#define _EDGE_CLASS

template <class V>
class Edge {
	V src;
	V dst;
	int edgeWeight;

public:
	Edge() : src(V(0)), dst(V(0)), edgeWeight(0) {}
	Edge(V s, V d) : src(s), dst(d), edgeWeight(0) {}
	Edge(V s, V d, int w) : src(s), dst(d), edgeWeight(w) {}
	
	void setSrcDst(const V& s, const V& d) { src = s; dst = d; }
	void setSrcDstWeight(const V& s, const V& d, int w) { src = s; dst = d; edgeWeight = w; }
	void setWeight(int w) { edgeWeight = w; }
	
	V getSrc() { return src; }
	V getDst() { return dst; }
	int getWeight() { return edgeWeight; }

};

#endif