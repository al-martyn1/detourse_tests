@rem WdNisSvc ���������_���: ������ �������� ���� ������������ ��������� Microsoft Defender (STOPPABLE, NOT_PAUSABLE, IGNORES_SHUTDOWN)
@rem WinDefend ���������_���: ������ ������������ ��������� Microsoft Defender (NOT_STOPPABLE, NOT_PAUSABLE, ACCEPTS_SHUTDOWN)
sc stop WdNisSvc
sc stop WinDefend
pause
