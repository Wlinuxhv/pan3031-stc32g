# GitHub 仓库设置指南

## 1. 创建 GitHub 仓库

1. 打开 https://github.com/new
2. 仓库名称：`pan3031-stc32g`
3. 描述：`PAN3031 Wireless Module Driver for STC32G12K128 MCU`
4. 设为 **Public** 或 **Private**（根据你的需求）
5. **不要** 勾选 "Add a README file"
6. **不要** 勾选 ".gitignore"
7. **不要** 选择许可证
8. 点击 "Create repository"

## 2. 获取仓库 URL

创建后，GitHub 会显示类似：
```
https://github.com/YOUR_USERNAME/pan3031-stc32g.git
```

## 3. 推送代码到 GitHub

在命令行执行（替换 YOUR_USERNAME 为你的 GitHub 用户名）：

```bash
cd C:\Users\User\.openclaw\workspace\pan3031_stc32g

# 添加远程仓库（替换为你的仓库 URL）
git remote add origin https://github.com/YOUR_USERNAME/pan3031-stc32g.git

# 推送到 GitHub
git push -u origin master
```

## 4. 启用 GitHub Actions

1. 进入你的仓库页面
2. 点击 "Actions" 标签
3. 如果看到 "I understand my workflows, go ahead and enable them"，点击启用
4. 第一次 push 后会自动触发构建

## 5. 下载 HEX 文件

构建成功后：
1. 进入仓库的 "Actions" 标签
2. 点击最近的构建记录
3. 在页面底部找到 "Artifacts"
4. 点击 `pan3031_stc32g_hex` 下载 HEX 文件

## 6. 发布版本（可选）

要创建带 HEX 文件的 Release：

```bash
# 打标签
git tag -a v1.0.0 -m "Initial release"

# 推送标签（会触发 Release 构建）
git push origin v1.0.0
```

---

## 快速命令（复制后替换用户名）

```bash
cd C:\Users\User\.openclaw\workspace\pan3031_stc32g
git remote add origin https://github.com/YOUR_USERNAME/pan3031-stc32g.git
git push -u origin master
```

## 遇到问题？

### 认证失败
使用 Personal Access Token 代替密码：
1. GitHub → Settings → Developer settings → Personal access tokens
2. 生成 token（勾选 repo 权限）
3. push 时用 token 作为密码

### 分支名不对
如果默认分支是 `main` 而不是 `master`：
```bash
git branch -M main
git push -u origin main
```
