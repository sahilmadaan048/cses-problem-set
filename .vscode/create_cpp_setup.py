import os

folder_name = input("Enter folder name: ").strip()
if not folder_name:
    print("❌ Folder name cannot be empty.")
    exit()

base_path = os.path.join(os.getcwd(), folder_name)
os.makedirs(base_path, exist_ok=True)

files = {
    "main.cpp": (
        "#include <bits/stdc++.h>\n"
        "using namespace std;\n\n"
        "int main() {\n"
        "    ios::sync_with_stdio(false);\n"
        "    cin.tie(nullptr);\n"
        "    // your code here\n"
        "    return 0;\n"
        "}\n"
    ),
    "input.txt": "",
    "output.txt": "",
    "error.txt": ""
}

for name, content in files.items():
    path = os.path.join(base_path, name)
    if not os.path.exists(path):
        with open(path, "w") as f:
            f.write(content)

print(f"✅ Created folder '{folder_name}' with 4 files.")
