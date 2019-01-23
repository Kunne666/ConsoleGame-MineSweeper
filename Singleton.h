//=======================================================================================
// singleton.h
// シングルトン関連のヘッダーファイル
//=======================================================================================

// 多重インクルードの防止
#ifndef INCLUDE_SingletonHeader
#define INCLUDE_SingletonHeader

template<class T>
class Singleton
{
public:
	static inline T* GetInstance()
	{
		static T instance;
		return &instance;
	}

protected:
	Singleton() {} 
	virtual ~Singleton() {}

private:
	void operator=(const Singleton& obj) {} 
	Singleton(const Singleton &obj) {} 
};

#endif // INCLUDE_SingletonHeader
