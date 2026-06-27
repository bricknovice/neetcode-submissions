class Solution {
public:

    typedef struct Node
    {
        string word;
        bool visited;
        Node(const string& w)
        {
            this->word = w;
            this->visited = false;
        };
    }Node_t;

    unordered_map<string, vector<Node_t*>> rec;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        Node_t* first = new Node_t(beginWord);
        for(int i=0; i< beginWord.size(); ++i)
        {
            std::string tmp = beginWord;
            tmp[i] = '-'; 
            rec[tmp].push_back(first);
        }

        for(int i=0; i< wordList.size(); ++i)
        {
            Node_t* curNode = new Node_t(wordList[i]);
            for(int j=0;j<wordList[i].size(); ++j)
            {
                std::string tmp = wordList[i];
                tmp[j] = '-'; 
                rec[tmp].push_back(curNode);
            }
        }

        queue<Node_t*> que;
        que.push(first);
        int level = 1;
        while(!que.empty())
        {
            int sz = que.size();
            for(int k=0;k<sz; k++)
            {
                Node_t* cur = que.front();
                que.pop();
                if(cur->word == endWord)
                    return level;
                if(cur->visited)
                    continue;
                printf("cur: %s\n", cur->word.c_str());
                cur->visited = true;
                for(int i=0;i<cur->word.size(); ++i)
                {
                    std::string tmp = cur->word;
                    tmp[i] = '-'; 
                    for(int j=0; j<rec[tmp].size(); ++j)
                    {
                        if(!rec[tmp][j]->visited)
                        {
                            printf("pushed: %s\n", rec[tmp][j]->word.c_str());
                            que.push(rec[tmp][j]);
                        }
                            
                    }
                }
            }
            level++;
        }

        return 0;

    }
};
