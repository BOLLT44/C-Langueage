#include <windows.h>

int Message() {
	return MessageBox(NULL, TEXT("\"��ģ\"��(��) ã�� �� �����ϴ�."), TEXT("Brain"), MB_RETRYCANCEL | MB_ICONERROR);
}

int main() {
	int i = MessageBox(NULL, TEXT("\"��ģ\"��(��) ã���ðڽ��ϱ�?"), TEXT("Brain"), MB_YESNO);

	if (i == IDNO) {
		return 0;
	}

	while (true) {
		int result = Message();

		if (result == IDRETRY) {
			continue;
		}
		else {
			break;
		}
	}


	return 0;
}