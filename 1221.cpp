#include <cstdio>
#include <cstring>

class SearchTree {
public:
	struct Node {
		Node(int data = 0x7fffffff) : data_(data), number_(1), l_son_(NULL), r_son_(NULL) {}
		void DeleteLSon() {
			if (l_son_) {
				l_son_->DeleteSon();
				delete l_son_;
				l_son_ = NULL;
			}
		}
		void DeleteRSon() {
			if (r_son_) {
				r_son_->DeleteSon();
				delete r_son_;
				r_son_ = NULL;
			}
		}
		void DeleteSon() {
			DeleteLSon();
			DeleteRSon();
		}
		int data_, number_;
		Node *l_son_, *r_son_;
	};

	SearchTree() : head_(new Node()) {}
	~SearchTree() {
		head_->DeleteSon();
		delete head_;
	}

	void Insert(int data) {
		Node *p = head_, *q = head_->l_son_;
		while(q) {
			if (q->data_ == data) {
				++q->number_;
				return;
			}
			p = q;
			if (q->data_ < data) q = q->r_son_;
			else q = q->l_son_;
		}
		if (p->data_ >= data) p->l_son_ = new Node(data);
		else p->r_son_ = new Node(data);
	}

	void Remove(int data) {
		Node *p = head_, *q = head_->l_son_;
		while(q && q->data_ != data) {
			p = q;
			if (q->data_ < data) q = q->r_son_;
			else q = q->l_son_;
		}
		Remove(p, q);
	}

	void Remove(Node *p, Node *q, bool total = 0) {
		if (q == NULL) return;
		if (!total && q->number_ > 1) {
			--q->number_;
			return;
		}
		if (q->l_son_ && q->r_son_) {
			Node *p2 = q, *q2 = q->l_son_;
			for (; q2->r_son_; p2 = q2, q2 = q2->r_son_);
			q->data_ = q2->data_;
			q->number_ = q2->number_;
			if (p2->l_son_ == q2) p2->l_son_ = q2->l_son_;
			else p2->r_son_ = q2->l_son_;
			delete q2;
		}
		else {
			Node *new_node = NULL;
			if (q->l_son_) 
				new_node = q->l_son_;
			else if (q->r_son_)
				new_node = q->r_son_;

			if (p->l_son_ == q)
				p->l_son_ = new_node;
			else
				p->r_son_ = new_node;
			delete q;
		}
	}
	void RemoveLessThan(int data) {
		RemoveLessThan(head_, head_->l_son_, data);
	}

	void RemoveLessThan(Node *p, Node *q, int data) {
		Node *tmp;
		while(q) {
			if (q->data_ <= data) {
				q->DeleteLSon();
				if (q->data_ == data) return;
				tmp = q;
				q = q->r_son_;
				if (p->l_son_ == tmp) p->l_son_ = q;
					else p->r_son_ = q;
				delete tmp;
			}
			else {
				p = q;
				q = q->l_son_;
			}
		}
	}

	void RemoveGreaterThan(int data) {
		RemoveGreaterThan(head_, head_->l_son_, data);
	}

	void RemoveGreaterThan(Node *p, Node *q, int data) {
		Node *tmp;
		for (; q;) {
			if (q->data_ >= data) {
				q->DeleteRSon();
				if (q->data_ == data)
					return;
				tmp = q;
				q = q->l_son_;
				if (p->l_son_ == tmp) p->l_son_ = q;
					else p->r_son_ = q;
				delete tmp;
			}
			else {
				p = q;
				q = q->r_son_;
			}
		}
	}

	void RemoveInvterval(int lower, int upper) {
		Node *p = head_, *q = head_->l_son_;
		while(q) {
			if (q->data_ < lower) {
				p = q;
				q = q->r_son_;
			}
			else if (q->data_ > upper) {
				p = q;
				q = q->l_son_;
			}
			else {
				RemoveGreaterThan(q, q->l_son_, lower);
				RemoveLessThan(q, q->r_son_, upper);
				if (q->data_ == lower || q->data_ == upper) return;
				Remove(p, q, 1);
				return;
			}
		}
	}

	bool Find(int data) {
		for (Node *p = head_->l_son_; p;) {
			if (p->data_ == data) return true;
			else if (p->data_ < data)
				p = p->r_son_;
			else
				p = p->l_son_;
		}
		return false;
	}

	Node *FindIth(int i) {
		return FindIth(head_->l_son_, i);
	}

	Node *FindIth(Node *node, int &i) {
		if (!node) return NULL;
		Node *tmp = FindIth(node->l_son_, i);
		if (tmp) return tmp;
		if (node->number_ >= i) return node;
		i -= node->number_;
		return FindIth(node->r_son_, i);
	}

	void Output() {
		if (head_->l_son_) Output(head_->l_son_);
		printf("\n");
	}

	void Output(Node *p) {
		if (p->l_son_) Output(p->l_son_);
		printf("%d,%d,%d ", p, p->data_, p->number_);
		if (p->r_son_) Output(p->r_son_);
	}
	Node *head_;
};

SearchTree tree;
int total_command_number, tmp1, tmp2;
char command[30];
SearchTree::Node *tmp;

int main() {

	scanf("%d", &total_command_number);
	for (int i = 0; i < total_command_number; ++i) {
		scanf("%s%d", command, &tmp1);
		if (!strcmp(command, "insert"))
			tree.Insert(tmp1);
		else if (!strcmp(command, "delete"))
			tree.Remove(tmp1);
		else if (!strcmp(command, "delete_less_than"))
			tree.RemoveLessThan(tmp1);
		else if (!strcmp(command, "delete_greater_than"))
			tree.RemoveGreaterThan(tmp1);
		else if (!strcmp(command, "delete_interval")) {
			scanf("%d", &tmp2);
			tree.RemoveInvterval(tmp1, tmp2);
		}
		else if (!strcmp(command, "find"))
			printf("%c\n", tree.Find(tmp1) ? 'Y' : 'N');
		else if (!strcmp(command, "find_ith")) {
			tmp = tree.FindIth(tmp1);
			if (tmp) printf("%d\n", tmp->data_);
			else printf("N\n");
		}
	}
}
