# Shell script for git push, using ssh

commit=$1

git add -A

git commit -m "$commit"

git push
