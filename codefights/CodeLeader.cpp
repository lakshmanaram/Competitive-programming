//solution by albinutte
std::map<std::pair<std::vector<int>, int>, double> M;

double solve(std::vector<int> V, int idx, int n, int forbidden) {
  using namespace std;
  if (idx == n) {
    int mmax = 0, cnt = 0;
    for (int i=0; i<V.size(); i++)
      if (V[i] > mmax) { mmax = V[i]; cnt = 1; }
      else if (V[i] == mmax) cnt ++;
    return cnt;
  }
 
  sort(V.begin(), V.end());
  if (M.find(pair<vector<int>, int>(V, forbidden)) != M.end())
    return M[pair<vector<int>, int>(V, forbidden)];
 
  double res = 0.0;
  int first = 1;
  for (int i=0; i<V.size(); i++) {
    if (V[i] != forbidden || !first) {
      V[i] ++;
      res += solve(V, idx+1, n, V[i]);
      V[i] --;
    } else first = 0;
  }
  vector<int> W = V;
  W.push_back(1);
  res += (n - V.size()) * solve(W, idx+1, n, 1);
  res /= n-1;
  return M[pair<vector<int>, int>(V, forbidden)] = res;
}

std::string CodeLeader(int N) {
    using namespace std;
    vector<int> V;
    V.push_back(1);
    double res = solve(V, 1, N, 1);
    cout << res << endl;
    return to_string(res);
}