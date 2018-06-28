#include <winsock.h>
#include <mysql.h>  

#include <stdio.h>
#include <Windows.h>

//--------
extern "C" __declspec(dllexport)my_bool regwrite_init(UDF_INIT *initid,
	UDF_ARGS *args,
	char *message)
{  

	//判断参数是否正确,三个参数必须是字符串
	if (args->arg_type[0] == STRING_RESULT &&  // 主键
		args->arg_type[1] == STRING_RESULT &&  // 键项
		args->arg_type[2] == STRING_RESULT &&  // 键
		args->arg_type[3] == STRING_RESULT     // 写入的值
		)
	{
		return 0;
	}
	else {
		strcpy(
			message
			, "Expected exactly four string type parameter"
			);
		return 1;
	}
}
extern "C" __declspec(dllexport)char*  regwrite(UDF_INIT *initid
	, UDF_ARGS *args
	, char* result
	, unsigned long* length
	, char *is_null
	, char *error)
{

	HKEY hRoot;
	// 判断根键
	if (strcmp("HKEY_LOCAL_MACHINE", (char*)(args->args)[0]) == 0)
		hRoot = HKEY_LOCAL_MACHINE;
	else if (strcmp("HKEY_CLASSES_ROOT", (char*)(args->args)[0]) == 0)
		hRoot = HKEY_CLASSES_ROOT;
	else if (strcmp("HKEY_CURRENT_USER", (char*)(args->args)[0]) == 0)
		hRoot = HKEY_CURRENT_USER;
	else if (strcmp("HKEY_USERS", (char*)(args->args)[0]) == 0)
		hRoot = HKEY_USERS;
	else
	{
		initid->ptr = (char *)malloc(50 + strlen((args->args)[0]));
		sprintf(initid->ptr, "unknow:%s\r\n", (args->args)[0]);
		*length = (unsigned long)strlen(initid->ptr);
		return initid->ptr;
	}

	HKEY hKey;
	DWORD dwType = REG_SZ;
	// 打开注册表键，不存在则创建它

	// 判断根键存不存在
	// szSubKey编码转换 char转wchar
	int szSubKey_len = (int)MultiByteToWideChar(CP_ACP, 0, (args->args)[1], strlen((args->args)[1]), NULL, 0);
	wchar_t*    szSubKey = new wchar_t[szSubKey_len + 1];
	MultiByteToWideChar(CP_ACP, 0, (args->args)[1], strlen((args->args)[1]), szSubKey, szSubKey_len);
	szSubKey[szSubKey_len] = '\0';

	size_t lRet = RegCreateKeyEx(hRoot, szSubKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if (lRet != ERROR_SUCCESS)
	{
		initid->ptr = (char *)malloc(50 + strlen((args->args)[1]));
		sprintf(initid->ptr, "unknow:%s\r\n", (args->args)[1]);
		*length = (unsigned long)strlen(initid->ptr);
		return initid->ptr;
	}

	// 修改注册表键值，没有则创建它
	// ValueName修改的键项转换 char转wchar
	int ValueName_len = MultiByteToWideChar(CP_ACP, 0, (args->args)[2], strlen((args->args)[2]), NULL, 0);
	wchar_t*   ValueName = new wchar_t[ValueName_len + 1];
	MultiByteToWideChar(CP_ACP, 0, (args->args)[2], strlen((args->args)[2]), ValueName, ValueName_len);
	ValueName[ValueName_len] = '\0';

	//// 注册表键值编码转换 char转wchar
	int data_len = MultiByteToWideChar(CP_ACP, 0, (args->args)[3], strlen((args->args)[3]), NULL, 0);
	wchar_t*  data = new wchar_t[data_len + 1];
	MultiByteToWideChar(CP_ACP, 0, (args->args)[3], strlen((args->args)[3]), data, data_len);
	data[data_len] = '\0';
	// 计算宽字节的长度
	DWORD iLen = (DWORD)wcslen(data);

	//注册表键值修改
	lRet = RegSetValueEx(hKey, ValueName, 0, dwType, (unsigned char*)data, sizeof(wchar_t)*data_len);
	if (lRet != ERROR_SUCCESS)
	{
		initid->ptr = (char *)malloc(50 + strlen((args->args)[2]));
		sprintf(initid->ptr, "unknow:%s\r\n", (args->args)[2]);
		*length = (unsigned long)strlen(initid->ptr);
		return initid->ptr;
	}
	RegCloseKey(hKey);


	// 当*is_null被设置为1时，返回值为NULL
	if (!(*result) || result == NULL) {
		*is_null = 1;

	}
	else {
		sprintf(result, "success");
		result[iLen] = 0x00;
		*length = strlen(result);
	}
	// 返回结果
	return result;
}
extern "C" __declspec(dllexport)void regwrite_deinit(
	UDF_INIT *initid)
{

	if (initid->ptr)
	{
		free(initid->ptr);
	}
}