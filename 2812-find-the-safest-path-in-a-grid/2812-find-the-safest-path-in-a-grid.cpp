class Solution {
public:

    struct Node {
        int safe;
        int id;
    };

    class MaxHeap {
    public:
        vector<Node> h;

        void push(Node x) {
            h.push_back(x);
            int i = h.size() - 1;

            while (i > 0) {
                int p = (i - 1) >> 1;

                if (h[p].safe >= h[i].safe)
                    break;

                swap(h[p], h[i]);
                i = p;
            }
        }

        Node pop() {
            Node res = h[0];

            h[0] = h.back();
            h.pop_back();

            int i = 0;

            while (true) {
                int l = i * 2 + 1;
                int r = l + 1;
                int best = i;

                if (l < h.size() && h[l].safe > h[best].safe)
                    best = l;

                if (r < h.size() && h[r].safe > h[best].safe)
                    best = r;

                if (best == i)
                    break;

                swap(h[i], h[best]);
                i = best;
            }

            return res;
        }

        bool empty() {
            return h.empty();
        }
    };


    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();
        int total = n * n;


        vector<int> dist(total, -1);


        // Manual BFS queue
        vector<int> q(total);
        int head = 0, tail = 0;


        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j]) {

                    int id = i*n+j;

                    dist[id] = 0;
                    q[tail++] = id;
                }
            }
        }


        static int dx[4] = {1,-1,0,0};
        static int dy[4] = {0,0,1,-1};



        // Multi-source BFS
        while(head < tail) {

            int id = q[head++];

            int x = id/n;
            int y = id%n;


            for(int k=0;k<4;k++) {

                int nx=x+dx[k];
                int ny=y+dy[k];


                if(nx>=0 && ny>=0 && nx<n && ny<n) {

                    int nid = nx*n+ny;


                    if(dist[nid] == -1) {

                        dist[nid] = dist[id]+1;

                        q[tail++] = nid;
                    }
                }
            }
        }



        vector<char> visited(total,0);


        MaxHeap pq;


        pq.push({dist[0],0});


        while(!pq.empty()) {


            Node cur = pq.pop();

            int id = cur.id;


            if(visited[id])
                continue;


            visited[id]=1;


            if(id == total-1)
                return cur.safe;



            int x=id/n;
            int y=id%n;



            for(int k=0;k<4;k++) {


                int nx=x+dx[k];
                int ny=y+dy[k];


                if(nx>=0 && ny>=0 && nx<n && ny<n) {


                    int nid = nx*n+ny;


                    if(!visited[nid]) {


                        int newSafe = min(cur.safe, dist[nid]);


                        pq.push({newSafe,nid});
                    }
                }
            }
        }


        return 0;
    }
};