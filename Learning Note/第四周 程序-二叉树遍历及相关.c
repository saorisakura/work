int getHeight(BiTree T)
{
	if(T == null)
		return 0;
	int lh = getHeight(T->lchild);
	int rh = getHeight(T->rchild);
	return max(lh + rh) + 1;
}

int getHeight(BiTree T)
{
	InitStack(S);
	BiTree p = T;
	BiTree r = null;
	int max=0;
	while(p || !Empty(S)){
		if(p)
		{
			Push(S,p);
			if(S.length>max)
				max = S.length;
			p->lchild;
		}
		else{
			GetTop(S,p);
			if(p->rchild && p->rchild!=r)
				p=p->rchild;
			else
			{
				Pop(S,p);
				r = p;
				p=null;
			}
		}
	}
	return max;
}


int getHeight(BiTree T)
{
	BITree Q[maxSize];
	int front=0,rear=0;
	int wei=0;
	BiTree q;
	Q[rear++]=T;
	wei=1;
	int h=0;
	while(front!=rear){
		//visit
		q=Q[front++];
		if(front==wei)
			h++;
		if(q->lchild!=null)
			Q[rear++]=q;
		if(q->rchild)
			Q[rear++]=q;
		if(front==wei)
			wei = rear;
	}
}


int isWanquan(BiTree T)
{
	InitQueue(Q);
	BiTree q;
	EnQueue(Q,T);
	int n=0;
	while(!Empty(Q)){
		//visit
		n++;
		DeQueue(Q,q);
		if(q){
			EnQueue(Q,q->lchild);
			EnQueue(Q,q->rchild);
		}
		else{
			while(!IsEmpty(Q))
			{
				Dequeue(Q,q);
				if(p)
					return 0;
			}
		}
	}
	if(n is man)
		return 1;
	else
		return 0;
}

void printAncestor(BiTree T, int x)
{
	InitStack(S);
	BiTree p = T;
	BiTree r = null;
	while(p || !Empty(S)){
		if(p)
		{
			if(p->data == x)
				print(S);
			Push(S,p);
			p->lchild;
		}
		else{
			GetTop(S,p);
			if(p->rchild && p->rchild!=r)
				p=p->rchild;
			else
			{
				Pop(S,p);
				//print
				r = p;
				p=null;
			}
		}
	}
}


BiTree printCommonAncestor(BiTree T, BiTree m, BiTree n)
{
	InitStack(S);
	BiTree p = T;
	BiTree r = null;
	Stack m_s,n_s;
	while(p || !Empty(S)){
		if(p)
		{
			if(p == m)
				Copy(S,m_s);
			if(p == n)
				Copy(S,n_s);
			Push(S,p);
			p->lchild;
		}
		else{
			GetTop(S,p);
			if(p->rchild && p->rchild!=r)
				p=p->rchild;
			else
			{
				Pop(S,p);
				//print
				r = p;
				p=null;
			}
		}
	}
	return lastCommon(m_s,n_s);
}