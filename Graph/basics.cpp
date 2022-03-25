/*
1 . in a complete graph ,all vertices are  connected to every other vertices.
2 . in a multigraph , there are more than one edges between two vertices.
3 . a->c , so c is adjacent to a but a is not adjacent to c.
4 . a strongly connected graph applies only to directed graph. here each vertex is reachable from every
other vertex.
5 . complete directed graph = there is a birectional edge btw each pair of vertices.
6 . kn = complete graph with n vertices.
7 . a cycle graph is a graph which consists of a single cycle and cntains 3 or more than three vertices connected in a chain.
8 . an adjacency list is represented as an array of linked list with each node pointing to every child of its node.every insertion
takes place in the front of the head.
9 . in adjacency list , time to check if an edge exists = O(V).
10 . A dag has atleast one vertex with in degree 0.
11 . topological sorting is a linear ordering of vertices such that if there is an edge u->v then u appears before v in that
ordering. a topological sort works only for DAG(directed acyclic graph).
12 . topological sort is not unique. there can be multiple solutions for topological sorting.
13 . if we cannot find a node with degree 0 then there can be 2 possibility either a cycle was encountered or the queue 
became empty. if the current counter is equal to total number of elements then the queue was empty else a cycle was en
countered and so topological sort is not possible.
14 . Walk = any random traversal in a graph(visit any edge or any vertex ,any number of times).
15 . Trail = a walk in which no edge is repeated.(vertices can be repeated).
16 . Euler Circuit = a trail which starts and ends at the same vertex is called Euler circuit.
if a graph has a euler circuit then the graph is a euler graph.

the 2 conditions for a circuit to be euler circuit are => a) start = end;
b) all edges must be visited only once.

=> the above 2 conditions can be summarised as - all the vertices should have even degree.

17 . An euler graph is a graph having euler circuit.
18 . all edges in a graph must be present in a single component(with previous 2 conditions).
19 . all other components should not have any edge and hence should be of size 1 vertex only.

20 . An euler Path is a path that visits every edge exactly once.
=>so euler circuit is a euler path that starts and ends at the same vertex.
21 . a semi eulerian graph conditions => a) every edge is visited once.
b) start vertex != end vertex.

here exactly 2 vertices should have same degree (start and end vertex) and all other vertices should have 
even degree. and all vertices with non zero degree must be connected.

22 . Fluery's algorithm is used to print the eulerian path or eulerian circuit.if the graph has no off odd degree
vertices 0 or 2 in count then it can be eulerpath(2) or eulercircuit(0).

for each vertex , always select the edge that is not a bridge as if we select a non bridge edge then we can come
back to that vertex and traverse remaining edges.

23 . Hierholzer's algorithm is used to print only the eulerian circuit.

*/