#include "FileReader.h"



FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}

void FileReader::LoadFileOBJ(string inputFileName, float ** points, float ** normals, float ** uvMap, unsigned int ** faces, int * nPoints, int * nFaces)
{
	ifstream inputFile;
	inputFile.open(inputFileName);

	vector<float> pointList, normalList, uvMapList;
	vector<unsigned int> faceList;

	int nFaceComponent = 0;

	if (inputFile.is_open())
	{
		bool meshCreated = false;
		bool humanDataFound = false;

		string line;
		while (getline(inputFile, line) && !meshCreated)
		{

			size_t vertexFound = line.find("v ");
			size_t texelFound = line.find("vt ");
			size_t faceFound = line.find("f ");


			if (vertexFound != string::npos)
			{
				std::size_t prev = 0, pos;
				while ((pos = line.find_first_of(" ", prev)) != std::string::npos)
				{
					if (pos > prev)
					{
						string token = line.substr(prev, pos - prev);
						if (token != "v")
						{
							float val = stof(token);

							pointList.push_back(val);
						}

					}
					prev = pos + 1;
				}
				if (prev < line.length())
				{
					string token = line.substr(prev, pos - prev);

					float val = stof(token);

					pointList.push_back(val);

				}
			}

			if (texelFound != string::npos)
			{
				std::size_t prev = 0, pos;
				while ((pos = line.find_first_of(" ", prev)) != std::string::npos)
				{
					if (pos > prev)
					{
						string token = line.substr(prev, pos - prev);
						if (token != "vt")
						{
							float val = stof(token);

							uvMapList.push_back(val);
						}

					}
					prev = pos + 1;
				}
				if (prev < line.length())
				{
					string token = line.substr(prev, pos - prev);

					float val = stof(token);

					uvMapList.push_back(val);

				}
			}


			if (faceFound != string::npos)
			{
				std::size_t prev = 0, pos;

				int idx = 0;

				while ((pos = line.find_first_of("/ ", prev)) != std::string::npos)
				{
					if (pos > prev)
					{
						string token = line.substr(prev, pos - prev);
						if (token != "f")
						{
							//if (idx % 2 == 0)
							//{
							int val = stoi(token);

							faceList.push_back((unsigned int)val - 1);
							//}

							idx++;
						}

					}
					prev = pos + 1;
				}
				if (prev < line.length())
				{
					string token = line.substr(prev, pos - prev);
					//if (idx % 2 == 0)
					//{
					int val = stoi(token);

					faceList.push_back((unsigned int)val - 1);
					//}
				}
			}




		}
	}
	else
	{
		cout << "Could not open file..." << endl;

		return;
	}

	cout << "Finished reading" << endl;

	float * pBuffer = new float[pointList.size()];
	float * uvBuffer = new float[uvMapList.size()];
	unsigned int * fBuffer = new unsigned int[faceList.size()];

	memcpy(pBuffer, &pointList[0], sizeof(float) * pointList.size());
	memcpy(uvBuffer, &uvMapList[0], sizeof(float) * uvMapList.size());
	memcpy(fBuffer, &faceList[0], sizeof(unsigned int) * faceList.size());

	if (points != NULL)
	{
		*points = pBuffer;
	}

	if (uvMap != NULL)
	{
		*uvMap = uvBuffer;
	}

	if (faces != NULL)
	{
		*faces = fBuffer;
	}

	*nFaces = faceList.size() / 4;

	*nPoints = pointList.size() / 3;

	cout << "Model loaded with " << *nFaces << " faces and " << *nPoints << " points " << endl;
}
