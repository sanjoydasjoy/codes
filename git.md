### Basic Command for initializing and pushing a Git repository to a remote

    git init
    git add .
    git commit -m "first commit"
    git branch -M main
    git remote add origin https://github.com/yourusername/repositoryname.git
    git push -u origin main

<br><br>

1. **`git init`** – Initializes a new Git repository by creating a `.git` folder.  
2. **`git add .`** – Stages all changes in the current directory for commit.  
3. **`git commit -m "first commit"`** – Saves the staged changes with a message.  
4. **`git branch -M main`** – Renames the current branch to `main`.  
5. **`git remote add origin <URL>`** – Links the local repo to a remote GitHub repository.  
6. **`git push -u origin main`** – Pushes the `main` branch to the remote repo and sets tracking.
