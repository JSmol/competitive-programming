/*  Euler Tour of rooted tree O(n)
 *  Usefull for sub tree query problems
 *  tour     = order of traversal
 *  enter[v] = fst idx of v in tour
 *  leave[v] = snd idx of v in tour 
 */

struct eulertour {
  int n; vector<vector<int>> A;
  eulertour(int n) : n(n), A(n) {}
  void add_edge(int a, int b) { A[a].push_back(b); A[b].push_back(a); }
  vector<int> tour, enter, leave, V;
  void dfs(int v) {
    enter[v] = sz(tour);
    tour.push_back(v); 
    V[v] = 1;
    for (auto& a : A[v])
      if (!V[a])
        dfs(a);
    leave[v] = sz(tour);
    tour.push_back(v);
  }
  vector<int> get_tour(int root = 0) {
    enter.assign(n, 0); leave.assign(n, 0); V.assign(n, 0);
    dfs(root);
    return tour;
  }
};

// sample queries on subtree
// range query tour on [ enter[v], leave[v] )
vector<int> tour = t.get_tour(0);
vector<int> enter = t.enter, leave = t.leave;
