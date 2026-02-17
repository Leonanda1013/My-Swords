export default async function ProductDetailPage({ params }: { params: Promise<{ id: string }> }) {
  const { id } = await params;
  console.log(id);

  return (
    <div>
      <h1>Product Detail Page for ID: {id}</h1>
    </div>
  );
}
