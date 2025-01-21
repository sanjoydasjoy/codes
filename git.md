### Key Terms
- [Basic Command for initializing and pushing a Git repository to a remote](#basic-command-for-initializing-and-pushing-a-git-repository-to-a-remote)
- [rm -rf .git](#rm--rf-git)
- [git status](#git-status)


### Basic Command for initializing and pushing a Git repository to a remote

    git init
    git add .
    git commit -m "first commit"
    git branch -M main
    git remote add origin https://github.com/yourusername/repositoryname.git
    git push -u origin main

<br><br>

1. **`git init`** – Initializes a new Git repository by creating a `.git` folder.  <br>
2. **`git add .`** – Stages all changes in the current directory for commit. <br>
3. **`git commit -m "first commit"`** – Saves the staged changes with a message. We can change the message to anything to describe the changes, like: git commit -m "Added login functionality" <br>
4. **`git branch -M main`** – Renames the current branch to `main`. Initially, Git used master as the default branch name. However, newer versions of Git (since 2020) default to main instead of master. If your Git still defaults to master, the command renames it to main. <br>
5. **`git remote add origin <URL>`** – Links the local repo to a remote GitHub repository. <br>
6. **`git push -u origin main`** – Pushes the `main` branch to the remote repo and sets tracking. <br>

___


<br><br><br>
### rm -rf .git

Running git init creates a .git folder, which makes a directory a Git repository by storing all version control data, including commits, branches, and settings. <br>
We use rm -rf .git to completely delete the Git history and configuration from a project, making it no longer a Git repository.

You should run `rm -rf .git` when:  

1. **Wrong Repository Initialization:** If you accidentally initialized Git in the wrong directory.  
2. **Corrupted Git Repository:** When the repository is broken or behaving unexpectedly.  
3. **Starting Fresh:** If you want to remove all version history and start tracking from scratch.  
4. **Before Cloning:** If you manually copied a project instead of cloning it and want to set up Git properly.  

**Avoid using it unless absolutely necessary, as it permanently deletes all Git history.**

The full form of rm -rf .git is:

rm – Remove <br>
-r – Recursive (deletes directories and their contents). <br>
-f – Force (deletes without confirmation, even if write-protected). <br>
.git – The hidden folder that stores Git repository data. <br>
    
This command forcefully and recursively deletes the .git folder, removing all version control history.

___
<br><br><br>

### git status

The command `git status` is used to display the state of the working directory and staging area. It provides useful information about the current state of your repository.

### What it shows:
1. **Current branch**: The branch you are working on (e.g., `main`, `develop`).
2. **Changes not staged for commit**: Files that have been modified but not added to the staging area yet.
3. **Untracked files**: Files that are in your working directory but aren't tracked by Git yet.
4. **Changes to be committed**: Files that have been added to the staging area and are ready to be committed.

### When and why to use `git status`:
- **When to use**:  
  - **Before committing**: To check which files are staged and which aren't.
  - **After modifying files**: To see what changes have been made since the last commit.
  - **Before pushing**: To ensure you are pushing the correct changes.
  - **Before pulling or merging**: To ensure your local changes won't conflict with the remote repository.

- **Why to use**:
  - **Keep track of your progress**: It helps you understand where you are in the development process.
  - **Avoid mistakes**: You can verify what is going to be committed or pushed, preventing unwanted changes from being added.
  - **Debugging**: Helps track any files that might have been missed or forgotten about during commits. 

### Example output of `git status`:
```bash
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   index.html
        modified:   app.js

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        newFile.txt

no changes added to commit (use "git add" and/or "git commit -a")

```

This tells you that `index.html` and `app.js` are modified but not yet staged, and `newFile.txt` is untracked (not added to Git yet).


