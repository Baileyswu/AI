void Tarjan(u) {
    dfn[u]=low[u]=++index
    stack.push(u)
    for each (u, v) in E {
        if (v is not visted) { 
            tarjan(v) 
            low[u] = min(low[u], low[v]) 
        } else if (v in stack) { 
            low[u] = min(low[u], dfn[v]) //low[u] = min(low[u], low[v])
        } 
    } 
    if (dfn[u] == low[u]) { //u��һ��ǿ��ͨ�����ĸ� 
        repeat 
            v = stack.pop 
            print v 
        until (u == v) 
    } //��ջ��������ǿ��ͨ������������ 
} //���Ӷ���O(E+V)��
