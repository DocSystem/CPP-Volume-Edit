#include <Windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <math.h>

double round(double d)
{
	return floor(d + 0.5);
}

/* ========================
=      Speakers Part      =
======================== */

void SetSpeakersVolume(int volume_level)
{
	double new_volume = round((double)volume_level / 100);
	HRESULT hr;

	CoInitialize(NULL);
	IMMDeviceEnumerator* deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
	IMMDevice* defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume* endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	hr = endpointVolume->SetMasterVolumeLevelScalar((float)new_volume, NULL);

	endpointVolume->Release();
	CoUninitialize();
}

int GetSpeakersVolume(void)
{
	HRESULT hr;

	CoInitialize(NULL);
	IMMDeviceEnumerator* deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
	IMMDevice* defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume* endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	float currentVolume = 0;
	hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);

	endpointVolume->Release();
	CoUninitialize();

	int ret = ceil(currentVolume * 100);
	return ret;
}

void SetSpeakersMute(bool mute) {
	HRESULT hr;

	CoInitialize(NULL);
	IMMDeviceEnumerator* deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
	IMMDevice* defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume* endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	hr = endpointVolume->SetMute(mute, NULL);

	endpointVolume->Release();
	CoUninitialize();
}

bool GetSpeakersMute(void) {

	HRESULT hr;

	CoInitialize(NULL);
	IMMDeviceEnumerator* deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
	IMMDevice* defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume* endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	BOOL mute;
	hr = endpointVolume->GetMute(&mute);

	endpointVolume->Release();
	CoUninitialize();

	return mute;
}

/* ========================
=     Microphone Part     =
======================== */

void SetMicrophoneVolume(int volume_level)
{
	double new_volume = round((double)volume_level / 100);
	HRESULT hr;

	CoInitialize(NULL);
	IMMDeviceEnumerator* deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
	IMMDevice* defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eCapture, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume* endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	hr = endpointVolume->SetMasterVolumeLevelScalar((float)new_volume, NULL);

	endpointVolume->Release();
	CoUninitialize();
}

int GetMicrophoneVolume(void)
{
	HRESULT hr;

	CoInitialize(NULL);
	IMMDeviceEnumerator* deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
	IMMDevice* defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eCapture, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume* endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	float currentVolume = 0;
	hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);

	endpointVolume->Release();
	CoUninitialize();

	int ret = ceil(currentVolume * 100);
	return ret;
}

void SetMicrophoneMute(bool mute) {
	HRESULT hr;

	CoInitialize(NULL);
	IMMDeviceEnumerator* deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
	IMMDevice* defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eCapture, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume* endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	hr = endpointVolume->SetMute(mute, NULL);

	endpointVolume->Release();
	CoUninitialize();
}

bool GetMicrophoneMute(void) {

	HRESULT hr;

	CoInitialize(NULL);
	IMMDeviceEnumerator* deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
	IMMDevice* defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eCapture, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume* endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	BOOL mute;
	hr = endpointVolume->GetMute(&mute);

	endpointVolume->Release();
	CoUninitialize();

	return mute;
}
