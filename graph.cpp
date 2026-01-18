#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> mat;
    int choice;

    while (true)
    {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Add Vertex\n";
        cout << "2. Add Edge\n";
        cout << "3. Delete Vertex\n";
        cout << "4. Print Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            // Add vertex
            mat.push_back(vector<int>());
            cout << "Vertex " << mat.size() - 1 << " added.\n";
        }
        else if (choice == 2)
        {
            int u, v;
            cout << "Enter two vertices to connect (u v): ";
            cin >> u >> v;
            if (u >= mat.size() || v >= mat.size())
            {
                cout << "Error: Vertex does not exist!\n";
            }
            else
            {
                mat[u].push_back(v);
                mat[v].push_back(u);
                cout << "Edge added between " << u << " and " << v << endl;
            }
        }
        else if (choice == 3)
        {
            int v;
            cout << "Enter vertex to delete: ";
            cin >> v;
            if (v >= mat.size())
            {
                cout << "Error: Vertex does not exist!\n";
            }
            else
            {
                // Remove all edges to/from this vertex
                for (int i = 0; i < mat.size(); i++)
                {
                    mat[i].erase(remove(mat[i].begin(), mat[i].end(), v), mat[i].end());
                    // decrement indices > v
                    for (int &x : mat[i])
                        if (x > v)
                            x--;
                }
                // Remove the vertex itself
                mat.erase(mat.begin() + v);
                cout << "Vertex " << v << " deleted.\n";
            }
        }
        else if (choice == 4)
        {
            // Print adjacency list
            cout << "\nGraph structure:\n";
            for (int i = 0; i < mat.size(); i++)
            {
                cout << i << " -> ";
                for (int x : mat[i])
                    cout << x << " ";
                cout << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
