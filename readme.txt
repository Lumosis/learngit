cd somedir	//切换到某个工作区
git init	//创建repo
--------------
git add somefile	//添加到暂存区
git commit -m blah	//提交
-------------
git status		//查看git当前状态
git diff somefile (-- somefile)	//查看file之间的区别
--------------
git log			//查看提交历史
git reset --hard HEAD^	//将工作区的文件恢复到上一个提交的状态
git reflog：		//查看所有操作历史？
git checkout -- somefile	//撤销工作区的修改
----------------------
git reset HEAD readme.txt	//将暂存区的修改撤销掉，重新放回工作区
---------------------
git rm somefile		
git commit -m "remove somfile"	//从版本库删除某文件，并且提交
git checkout -- somefile	//在工作区删错文件，从版本库中恢复
---------------------
git remote add origin git@github.com:username/repo-name.git	//将远程库与本地库相关联
git push -u origin master	//推送，加-u实现关联（第一次）
-----------------------------------
git clone git@github.com:Lumosis/repo_name	//克隆到本地
-----------------------------------
git checkout -b dev =
git branch dev + git checkout dev	//建立并切换新的分支
------------------------------
git branch		//查询分支
-------------------------
git merge dev		//合并分支
------------------------
git branch -d dev	//删除分支
-------------------------
企图合并>>合并失败>>修改>>提交（合并成功）>>删除多余分支
git log --graph		//查看分支合并图
-------------------------
git stash //保存现场，（暂时离开）
git stash pop //恢复现场
---------------------------
多人协作：
1.首先，可以试图用git push origin branch-name推送自己的修改；

2.如果推送失败，则因为远程分支比你的本地更新，需要先用git pull试图合并；

3.如果合并有冲突，则解决冲突，并在本地提交；

4.没有冲突或者解决掉冲突后，再用git push origin branch-name推送就能成功！

如果git pull提示“no tracking information”，则说明本地分支和远程分支的链接关系没有创建，
用命令 git branch --set-upstream branch-name origin/branch-name
-------------------------

