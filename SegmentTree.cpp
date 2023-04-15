class SegmentTree{
    vector<int> tree;
    SegmentTree(int n){
        tree.resize(n,0);
    }

    void build(int node, vector<int> &arr, int start, int end){

        if(start==end){
            tree[node] = arr[start];
        }
        int mid = start + (start-end)/2;
        build(2*node,arr,start,mid);
        build(2*node+1,arr,mid+1,end);
        tree[node] = tree[2*node]+tree[2*node+1];
    }

    void update(int idx, int value, int node, vector<int> &arr, int start, int end){
        if(start==end){
            arr[idx] += value;
            tree[node] += value;
        }

        int mid = start + (end-start)/2;
        if(idx>=start && idx<=mid){
            update(idx,value,2*node,arr,start,mid);
        } else {
            update(idx,value,2*node+1,arr,mid+1,end);
        }
        tree[node] = tree[2*node]+tree[2*node+1];
    }

    int query(int node, vector<int> &arr, int start, int end, int l, int r){
        if(r<start || l>end){
            return 0;
        }

        if(l<=start && r>=end){
            return tree[node];
        }

        int mid = start+(start-end)/2;
        int p1 = query(2*node,arr,start,mid,l,r);
        int p2 = query(2*node+1,arr,mid+1,end,l,r);
        return (p1+p2);
    }
};

class Solve(){
    int main(){
        vector<int>arr; // main array
        int n; // size of the array
        SegmentTree root = new SegmentTree(n);
        root.build(1,arr,0,n-1);

        int indexToBeUpdated, value;
        root.update(indexToBeUpdated,value,1,arr,0,n-1);

        int lQuery,rQuery;
        int ans = root.query(1,arr,0,n-1,lQuery,rQuery);

    }
}