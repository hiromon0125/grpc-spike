# gRPC C++ implementation

This is a simple C++ gRPC server that logs every TalosOperator request and returns placeholder responses.

## Build
- Open the workspace in the dev container.
- Configure once: `cmake -S cpp-ws -B build`
- Incremental builds: `cmake --build build`

## Run
- Execute `./build/talos`

## Updating generated protobuf code
1. Edit `proto/icd.proto` with the new message or service changes.
2. Rebuild the C++ target: `cmake --build build` regenerates the C++ stubs in `build/generated` automatically.
